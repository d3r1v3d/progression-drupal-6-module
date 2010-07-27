<div class="progression_counter">
    <p>Title: <?php print $title; ?></p>
    <p>Type: <?php print $counterType; ?></p>
    <p>
        Target Date: <?php print $targetDate['year'] . '/' 
                                 . (($targetDate['month'] < 10) ? '0' . $targetDate['month'] : $targetDate['month']) . '/' 
                                 . (($targetDate['day'] < 10) ? '0' . $targetDate['day'] : $targetDate['day']); ?>
    </p>
</div>
