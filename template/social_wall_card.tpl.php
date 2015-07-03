<blockquote>
<header>
<time datetime="<?php echo $post->getCreatedAt()->format('Y-m-d H:i:s') ?>"><?php echo format_date($post->getCreatedAt()->format('U')) ?></time>
    <p><?php echo $post->getAuthor()->getName() ?></p>
</header>
<p>
<?php echo $post->getMessage() ?>
</p>
</blockquote>
