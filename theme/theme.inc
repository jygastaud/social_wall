<?php

/**
 * Implements hook_preprocess_social_wall_card().
 */
function template_preprocess_social_wall_card(&$variables) {
  // get type of the post
  $type = social_wall_get_post_type($variables['post']);
  $variables['type'] = $type;
  $variables['classes_array'][] = 'social-wall-card--' . $type;

  $types = social_wall_get_post_types();

  $typeNames = array_keys($types);

  foreach($typeNames as $typeName) {
    $variables['theme_hook_suggestions'][] = 'social_wall_card__' . $typeName;
  }

  $variables['classes'] = implode($variables['classes_array']);

  $post = $variables['post'];

  // prepare profile picture
  $profile_picture_image = array(
    '#theme' => 'imagecache_external',
    '#path' => $post->getAuthor()->getProfilePicture()->getUrl(),
    '#style_name' => 'sw_profile_picture'
  );

  $variables['profile_picture'] = array(
    '#theme' => 'link',
    '#text' => drupal_render($profile_picture_image),
    '#path' => $post->getAuthor()->getLink(),
    '#options' => array(
      'attributes' => array(),
      'html' => TRUE,
    )
  );

  // prepare post medias
  $variables['medias'] = array();

  foreach($post->getMedias() as $media) {

    $image = array(
      '#theme' => 'imagecache_external',
      '#path'       => $media->getUrl(),
      '#style_name' => 'sw_post_picture',
      '#attributes' => array(
        'class' => array('img-responsive')
      )
    );

    $variables['medias'][] = array(
      '#theme' => 'link',
      '#text' => drupal_render($image),
      '#path' => $media->getLink(),
      '#options' => array(
        'attributes' => array(),
        'html' => TRUE,
      ),
    );
  }
}

/**
 * Implements hook_preprocess_social_wall_feed().
 */
function template_preprocess_social_wall_feed(&$variables) {
  libraries_load('salvattore');

  $variables['classes'] = implode($variables['classes_array']);

  $posts_render_array = array();

  $interval = 60 * 5;

  foreach($variables['social_feed']->getFeed() as $post) {
    $posts_render_array[] = array(
      '#theme' => 'social_wall_card',
      '#post' => $post,
      '#cache' => array(
        'keys' => array('social_wall', 'post', $post->getIdentifier()),
        'expire' => time() + $interval,
        'granularity' => DRUPAL_CACHE_PER_ROLE,
      ),
    );
  }

  $variables['posts'] = $posts_render_array;
}
