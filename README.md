# Social Wall Drupal Module

## Installation

social wall module depends on SocialFeed PHP lib available in packagist, you can install this lib using composer : `composer require lns/social-feed`

## Usage

social wall create a new block named social wall, you can include this block in your page.

to add configure your twitter and facebook keys enable corresponding modules then go to admin pages :
* admin/config/social_wall/facebook
* admin/config/social_wall/twitter
* …

to add a source to your feed use `hook__social_wall_social_feed_alter` :

```
// see  social_wall_example/social_wall_example.module
/**
 * Implements hook_TYPE_alter.
 */
function social_wall_example_social_wall_social_feed_alter(&$socialFeed) {
  $socialFeed
    ->addSource(new Source(
      social_wall_get_provider('facebook_page'),
      array('page_id' => '107564825946579')
    ))
    ->addSource(new Source(
      social_wall_get_provider('twitter_search_api'),
      array('query' => 'afriqueInnovation')
    ))
    ;
`
```


