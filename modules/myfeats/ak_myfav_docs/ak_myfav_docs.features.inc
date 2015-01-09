<?php
/**
 * @file
 * ak_myfav_docs.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ak_myfav_docs_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function ak_myfav_docs_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favourites".
  $flags['favourites'] = array(
    'content_type' => 'node',
    'title' => 'Favourites',
    'global' => 0,
    'types' => array(
      0 => 'priv_documentation',
    ),
    'flag_short' => 'Add to Favorites',
    'flag_long' => 'Add this item to your favorites',
    'flag_message' => 'This item is added to your favorites',
    'unflag_short' => 'Remove From Favorites',
    'unflag_long' => '',
    'unflag_message' => 'This item is deleted from your favorites',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ak_myfav_docs',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}
