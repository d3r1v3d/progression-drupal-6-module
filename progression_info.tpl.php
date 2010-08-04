<?php
    // TODO: get a better handle on how theme variables are registered to avoid this wonkiness...
    $params = $title; 
?>
<div class="progression_counter">
    <p><i>Title:</i> <?php print $params['title']; ?></p>
    <p><i>Type:</i> <?php print $params['counterType']; ?></p>
    <p>
        <i>Target Date:</i> 
        <?php print $params['targetDate']['year'] . '/' 
              . (($params['targetDate']['month'] < 10) ? '0' . $params['targetDate']['month'] : $params['targetDate']['month']) . '/' 
              . (($params['targetDate']['day'] < 10) ? '0' . $params['targetDate']['day'] : $params['targetDate']['day']); ?>
    </p>
    <p><i>Description:</i><br/><?php print nl2br(htmlentities($params['description']), TRUE); ?></p>
</div>
