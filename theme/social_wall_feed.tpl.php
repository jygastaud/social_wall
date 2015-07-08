<div class="row">
    <section class="<?php echo $classes ?>" data-columns>
        <?php foreach($feed as $post): ?>
            <?php echo theme('social_wall_card', array('post' => $post)) ?>
        <?php endforeach ?>
    </section>
</div>
