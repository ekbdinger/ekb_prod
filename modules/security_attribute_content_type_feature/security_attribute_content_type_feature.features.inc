<?php
/**
 * @file
 * security_attribute_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function security_attribute_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function security_attribute_content_type_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function security_attribute_content_type_feature_node_info() {
  $items = array(
    'security_attribute' => array(
      'name' => t('Security Attribute'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
