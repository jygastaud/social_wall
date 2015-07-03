<?php

/**
 * @file social_wall.api.php
 * Hooks provided by the Social wall module.
 */

function hook_social_wall_social_feed_alter(&$socialFeed) {
    $socialFeed
        ->addSource(social_wall_get_provider('facebook_page'), array('page_id' => 'your_page_id'))
        ->addSource(social_wall_get_provider('twitter_search_api'), array('query' => 'your_search'))
    ;
}
