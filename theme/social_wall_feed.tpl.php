<article class="<?php echo $classes ?>">
<?php foreach($feed as $post): ?>
<?php echo theme('social_wall_card', array('post' => $post)) ?>
<?php endforeach ?>
</article>
