<?php
/**
 * @file
 * security_attribute_content_type_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function security_attribute_content_type_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_security-attribute-search:resources/security-attribute/search
  $menu_links['main-menu_security-attribute-search:resources/security-attribute/search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'resources/security-attribute/search',
    'router_path' => 'resources/security-attribute/search',
    'link_title' => 'Security Attribute Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_security-attribute-search:resources/security-attribute/search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:node/14110',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Security Attribute Search');


  return $menu_links;
}
