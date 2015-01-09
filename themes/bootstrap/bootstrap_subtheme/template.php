<?php
/**
 * @file
 * template.php
 *
 * This file should only contain light helper functions and stubs pointing to
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `theme` folder named after the
 * function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template implementations also
 * live in the 'theme' folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 * @see _bootstrap_theme()
 * @see theme/registry.inc
 *
 * Due to a bug in Drush, these includes must live inside the 'theme' folder
 * instead of something like 'includes'. If a module or theme has an 'includes'
 * folder, Drush will think it is trying to bootstrap core when it is invoked
 * from inside the particular extension's directory.
 * @see https://drupal.org/node/2102287
 */

/**
 * Include common functions used through out theme.
 */
include_once dirname(dirname(__FILE__)) . '/theme/common.inc';

/**
 * Implements hook_theme().
 *
 * Register theme hook implementations.
 *
 * The implementations declared by this hook have two purposes: either they
 * specify how a particular render array is to be rendered as HTML (this is
 * usually the case if the theme function is assigned to the render array's
 * #theme property), or they return the HTML that should be returned by an
 * invocation of theme().
 *
 * @see _bootstrap_theme()
 */
function bootstrap_subtheme_theme(&$existing, $type, $theme, $path) {
  bootstrap_include($theme, 'theme/registry.inc');
  //return _bootstrap_theme($existing, $type, $theme, $path);
  $hooks['user_login'] = array(
    'template' => 'templates/user_login',
    'render element' => 'form',
    // other theme registration code...
  );
  return $hooks;
}

function bootstrap_subtheme_preprocess_node(&$variables, $hook) {
  $node = $variables['node'];
  $variables['unpublished'] = ($variables['status']) ? TRUE : FALSE;
}

/**
 * Overrides theme_menu_link().
 */
function bootstrap_subtheme_menu_link__menu_block__1($variables) {
  return theme_menu_link($variables);
}

/**
 * Declare various hook_*_alter() hooks.
 *
 * hook_*_alter() implementations must live (via include) inside this file so
 * they are properly detected when drupal_alter() is invoked.
 */

// function bootstrap_subtheme_menu_tree(&$variables) {
//   return '<div class="nav-collapse"><ul class="menu nav">' . $variables['tree'] . '</ul></div>'; // added the nav-collapse wrapper so you can hide the nav at small size
// }

// function bootstrap_subtheme_menu_link(array $variables) {
//   $element = $variables['element'];
//   $sub_menu = '';
//     if ($element['#below']) {
//     // Ad our own wrapper
//     unset($element['#below']['#theme_wrappers']);
//     $sub_menu = '<ul>' . drupal_render($element['#below']) . '</ul>'; // removed flyout class in ul
//     unset($element['#localized_options']['attributes']['class']); // removed flydown class
//     unset($element['#localized_options']['attributes']['data-toggle']); // removed data toggler
//     // Check if this element is nested within another
//     if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
//       unset($element['#attributes']['class']); // removed flyout class
//     }
//     else {
//       unset($element['#attributes']['class']); // unset flyout class
//       $element['#localized_options']['html'] = TRUE;
//       $element['#title'] .= ''; // removed carat spans flyout
//     }
//     // Set dropdown trigger element to # to prevent inadvertent page loading with submenu click
//     $element['#localized_options']['attributes']['data-target'] = '#'; // You could unset this too as its no longer necessary.
//   }
//   //$output = l($element['#title'], $element['#href'], $element['#localized_options']);
//   print_r($output);exit();
//   //return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
// }


bootstrap_include('bootstrap', 'theme/alter.inc');

 function bootstrap_subtheme_preprocess_page(&$variables) {
    $main_menu_tree = menu_tree_all_data('main_menu');
    $vars['main_menu_expanded'] = menu_tree_output($main_menu_tree);
    //create page.tpl.php and add <?php print render($main_menu_expanded); 
  }

  function bootstrap_subtheme_preprocess_user_login(&$variables) {
    $variables['intro_text'] = t('This is my awesome login form');
    $variables['rendered'] = drupal_render_children($variables['form']);
  }

?> 