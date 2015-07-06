<?php

use Lns\SocialFeed\Source;

/**
 * @file social_wall.api.php
 * Hooks provided by the Social wall module.
 */

/**
 * Implements hook_TYPE_alter.
 */
function hook_social_wall_social_feed_alter(&$socialFeed) {
    $socialFeed
        ->addSource(new Source(social_wall_get_provider('facebook_page'), array('page_id' => 'your_page_id')))
        ->addSource(new Source(social_wall_get_provider('twitter_search_api'), array('query' => 'your_search')))
    ;
}

/**
 * Implements hook_social_wall_providers.
 */
function hook_social_wall_providers() {
  return array(
      new MyCustomProvider1(),
      new MyCustomProvider2()
  );
}

