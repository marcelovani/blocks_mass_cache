<?php
/**
 * @file
 * Contains the administrative functions of the blocks_mass_cache module.
 *
 * This file is included by the core Blocks Mass Cache module, and includes the
 * settings form.
 */

/**
 * Implements hook_admin_settings_form().
 * 
 * Used to create the admin form to configure the blocks_mass_cache blocks.
 */
function blocks_mass_cache_admin_settings_form($form_id, $form_state) {
  global $theme_key;
  $form = array();

  // Populate all blocks for the current theme.
  module_load_include('inc', 'block', 'block.admin');
  drupal_theme_initialize();
  if (!isset($theme)) {
    // If theme is not specifically set, rehash for the current theme.
    $theme = $theme_key;
  }
  // Get blocks list.
  $block_list = block_admin_display_prepare_blocks($theme);

  // Build the form.
  $form['blocks_mass_cache_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable global cache for blocks (per page).',
    '#default_value' => variable_get('blocks_mass_cache_enabled', TRUE),
    '#weight' => -1,
  );
  $form['blocks_mass_cache_exception_list'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global Cache Exception List'),
    '#weight' => 0,
  );
  $form['blocks_mass_cache_exception_list']['description'] = array(
    '#markup' => t("All blocks are set to be cached globally, per page, tick the blocks that are not supposed to be cached globally."),
  );

  // Load stored list of exceptions.
  $exception_list = variable_get('blocks_mass_cache_exception_list', array());

  $options = array();

  // Load system blocks.
  foreach ($block_list as $block) {
    // Build block id string.
    $bid = $block['module'] . '-' . $block['delta'];
    $options[$bid] = $block['info'];
  }

  // Display entities to choose to fine-tune setting.
  $form['blocks_mass_cache_exception_list']['block_mass_cache_exception_list'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => $exception_list,
  );

  return system_settings_form($form);
}
