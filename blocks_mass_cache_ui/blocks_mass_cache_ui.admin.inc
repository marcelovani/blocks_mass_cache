<?php
/**
 * @file
 * Blocks Mass cache admin UI.
 */

/**
 * Menu callback.
 */
function blocks_mass_cache_ui_admin_blocks($form, $form_state, $rid = NULL) {

  // Retrieve cache types to be placed on the table columns.
  $cache_types = _blocks_mass_cache_get_cache_types();
  if (is_numeric($rid)) {
    $cache_types = array($rid => $cache_types[$rid]);
  }

  // Store $cache_types in the form.
  $form['cache_types'] = array(
    '#type' => 'value',
    '#value' => $cache_types,
  );

  // Block cache configuration.
  $blocks_cache_config = _blocks_mass_cache_blocks_cache_config($cache_types);

  $options = array();
  foreach (_blocks_mass_cache_block_list() as $module_name => $block_group) {

    $form['blocks'][] = array(
      '#markup' => ucfirst($module_name),
      '#id' => $module_name,
    );

    foreach ($block_group as $block => $item) {
      $bid = _blocks_mass_cache_get_bid($item);
      $options[$bid] = '';
      $form['blocks'][$bid] = array(
        '#type' => 'item',
        '#markup' => $item['info'],
        '#description' => '',
      );
      foreach ($cache_types as $cache_id => $name) {
        // Builds arrays for checked boxes for each role
        if (isset($blocks_cache_config[$cache_id][$bid]) && $blocks_cache_config[$cache_id][$bid] == $cache_id) {
          $status[$cache_id][$bid] = $bid;
        }
      }
    }
  }

  // Have to build checkboxes here after checkbox arrays are built.
  foreach ($cache_types as $cache_id => $name) {
    $form['checkboxes'][$cache_id] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => isset($status[$cache_id]) ? $status[$cache_id] : array(),
      '#attributes' => array('class' => array('rid-' . $cache_id)),
    );
    $form['cache_types'][$cache_id] = array('#markup' => check_plain($name), '#tree' => TRUE);
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save'));

  $form['#attached']['js'][] = drupal_get_path('module', 'blocks_mass_cache_ui') . '/blocks_mass_cache_ui.js';

  return $form;
}
