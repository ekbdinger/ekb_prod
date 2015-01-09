<?php
/**
 * @file
 * security_attribute_content_type_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function security_attribute_content_type_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-security_attribute-field_action'
  $field_instances['node-security_attribute-field_action'] = array(
    'bundle' => 'security_attribute',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_action',
    'label' => 'Action',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          1 => 1,
          2 => 2,
          3 => 3,
          4 => 4,
          'test_format' => 'test_format',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            1 => array(
              'weight' => -9,
            ),
            2 => array(
              'weight' => -10,
            ),
            3 => array(
              'weight' => -8,
            ),
            4 => array(
              'weight' => -6,
            ),
            'test_format' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Action');

  return $field_instances;
}
