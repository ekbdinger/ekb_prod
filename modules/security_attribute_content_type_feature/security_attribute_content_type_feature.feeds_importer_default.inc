<?php
/**
 * @file
 * security_attribute_content_type_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function security_attribute_content_type_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'security_attribute_node_importer';
  $feeds_importer->config = array(
    'name' => 'Security Attribute node importer',
    'description' => 'import the security attribute content type',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Security Item',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Action',
            'target' => 'field_action',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => '2',
        'skip_hash_check' => 0,
        'bundle' => 'security_attribute',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['security_attribute_node_importer'] = $feeds_importer;

  return $export;
}
