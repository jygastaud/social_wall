<article class="<?php echo $classes ?>">
    <header class="clearfix">
        <div class="social-wall-card__icon-wrap">
            <svg class="icon-social-feed icon-social-feed--<?php echo $type ?>" width="32px" height="32px">
                <use xlink:href="#<?php echo $type ?>" />
            </svg>
        </div>

        <div class="social-wall-card__account">
            <div>
                <a href="#">
                    <?php echo theme('imagecache_external', array(
                        'path'       => $post->getAuthor()->getProfilePicture()->getUrl(),
                        'style_name' => 'sw_profile_picture'
                    )) ?>
                </a>
            </div>
            <div>
                <p><?php echo $post->getAuthor()->getName() ?></p>
                <time datetime="<?php echo $post->getCreatedAt()->format('Y-m-d H:i:s') ?>"><?php echo format_date($post->getCreatedAt()->format('U')) ?></time>
            </div>
        </div>
    </header>
    <blockquote class="social-wall-card__msg">
        <?php echo $post->getMessage() ?>
    </blockquote>
    <?php foreach($post->getMedias() as $media): ?>
        <?php echo theme('imagecache_external', array(
            'path'       => $media->getUrl(),
            'style_name' => 'sw_post_picture'
        )) ?>
    <?php endforeach ?>
</article>
