<article class="<?php echo $classes ?>">
    <header>
        <div class="pull-left">
            <a href="#">
                <img class="media-object" src="<?php echo $post->getAuthor()->getProfilePicture()->getUrl() ?>"></img>
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
        <img class="img-responsive" src="<?php echo $media->getUrl() ?>"></img>
    <?php endforeach ?>
</article>
