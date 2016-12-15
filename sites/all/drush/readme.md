#Drush Config

* Aliases are stored in sites/all/drush/aliases folder.
* Commands are stored in sites/all/commands folder.

These drush configs are automatically loaded by the latest version of drush as
long as you're working inside the docroot directory.

If you want your drush aliases loaded on the root directory you can create
a drushrc.php located in ```~/.drush/drushrc.php```. This will give you the drush
settings without needing to be inside the docroot folder.

```php
<?php

/**
 * Load a drushrc file from the 'docroot/sites/all/drush' folder of the current
 * git repository.
 */
exec('git rev-parse --show-toplevel 2> /dev/null', $output);
if (!empty($output)) {
 $repo = $output[0];
 $options['config'] = $repo . '/docroot/sites/all/drush/drushrc.php';
}
```
