<?php

/**
 * Implements hook_preprocess_social_wall_card().
 */
function template_preprocess_social_wall_card(&$variables) {
  // get type of the post
  $type = social_wall_get_post_type($variables['post']);
  $variables['type'] = $type;
  $variables['classes_array'][] = 'social-wall-card-' . $type;

  $types = social_wall_get_post_types();

  $typeNames = array_keys($types);

  foreach($typeNames as $typeName) {
    $variables['theme_hook_suggestions'][] = 'social_wall_card__' . $typeName;
  }

  $variables['classes'] = implode($variables['classes_array']);
}

/**
 * Implements hook_preprocess_social_wall_feed().
 */
function template_preprocess_social_wall_feed(&$variables) {

  $variables['classes'] = implode($variables['classes_array']);
}
