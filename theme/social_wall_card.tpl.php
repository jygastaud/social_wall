<article class="<?php echo $classes ?>">
    <header>
        <div class="icon-wrapper">
            <svg class="icon social-card-icon-type">
                <use xlink:href="#<?php echo $type ?>" />
            </svg>
        </div>
        <div class="pull-left">
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
    </header>
    <blockquote>
        <?php echo $post->getMessage() ?>
    </blockquote>
    <?php foreach($post->getMedias() as $media): ?>
        <?php echo theme('imagecache_external', array(
            'path'       => $media->getUrl(),
            'style_name' => 'sw_post_picture'
        )) ?>
    <?php endforeach ?>
</article>
