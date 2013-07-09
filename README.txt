
Module: Blocks Mass Cache

Description
===========
Set global caching for blocks


Installation
============
Copy the module directory in to your Drupal:
/sites/all/modules directory as usual.


Configuration
====================================================
Visit /admin/structure/block/mass-cache
or menus: Structure > Blocks > Mass Cache settings

Tick the option to enable it and select the blocks you
do not want to apply mass caching.

IMPORTANT: In Drupal, blocks are not cached if you are
logged in as admin (user id 1).

Also, make sure that "Cache Blocks" is enabled on
Configuration > Development > Performance