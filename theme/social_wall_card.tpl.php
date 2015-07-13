<article class="<?php print $classes ?>" data-identifier="<?php print $post->getIdentifier() ?>" data-type="<?php print $type ?>">
    <header class="clearfix social-wall-card__header">
        <div class="social-wall-card__icon-wrap">
            <svg class="icon-social-feed icon-social-feed--<?php print $type ?>" width="32px" height="32px">
                <use xlink:href="#<?php print $type ?>" />
            </svg>
        </div>
        <div class="social-wall-card__actions">
            <?php print render($actions) ?>
        </div>
        <div class="social-wall-card__account">
            <div>
                <?php print render($profile_picture) ?>
            </div>
            <div>
                <?php if($post->getAuthor()->getUsername()): ?>
                <p>
                    <?php print $post->getAuthor()->getName() ?>
                </p>
                <p class="social-wall-card__account__screen-name">
                    <a href="<?php print $post->getAuthor()->getLink() ?>">
                        <?php print '@' . $post->getAuthor()->getUsername() ?>
                    </a>
                </p>
                <?php else: ?>
                <p>
                    <a href="<?php print $post->getAuthor()->getLink() ?>">
                        <?php print $post->getAuthor()->getName() ?>
                    </a>
                </p>
                <?php endif ?>
            </div>
        </div>
    </header>
    <blockquote class="social-wall-card__msg">
        <?php print social_wall_format_message($post->getMessage(), $post->getReferences(), $type) ?>
    </blockquote>
    <div class="social-wall-card__illu">
        <?php print render($medias) ?>
    </div>

    <footer class="social-wall-card__footer">
        <time datetime="<?php print $post->getCreatedAt()->format('Y-m-d H:i:s') ?>"><?php print format_date($post->getCreatedAt()->format('U')) ?></time>
    </footer>
</article>

