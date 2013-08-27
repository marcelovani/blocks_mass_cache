Module: Blocks Mass Cache

Description
===========
Set global caching for blocks as "Per page".
It is possible to choose which blocks you do not want to be affected, 
keeping the original cache settings.

Installation
============
Copy the module directory in to your Drupal:
/sites/all/modules directory as usual.


Configuration
====================================================
Visit /admin/structure/block/mass-cache
or via menus: Structure > Blocks > Mass Cache settings

Tick the option to enable it and select the blocks you
DO NOT want to apply mass caching.

Also, make sure that "Cache Blocks" is enabled on
Configuration > Development > Performance

Flush blocks cache or all caches

IMPORTANT: In Drupal, blocks are not cached if you are logged in 
as admin (user id 1), so make sure you test blocks caching with 
an user different than user 1 or as anonymous.
