<?php

/**
 * Describes the Progression counter tables to the Views 2 module. Allows users to add counter-specific information
 * such as counter types, target dates, etc as fields in their Views.
 */
function progression_views_data() {
    // set prefix for Progression data that will be used in the Views UI
    $data['progression_counter']['table']['group'] = t('Counter');
    
    $data['progression_counter']['table']['base'] = array(
        'field' => 'nid',
        'title' => t('Counter'),
        'help' => t('Describes countups and countdowns.'),
        'weight' => -10
    );

    $data['progression_counter']['table']['join'] = array(
        'node' => array(
            'left_field' => 'nid',
            'field' => 'nid'
        )
    );

    $data['progression_counter']['nid'] = array(
        'title' => t('Node ID'),
        'help' => t('Counter object that references a node.'),
        'relationship' => array(
            'base' => 'node',
            'field' => 'nid',
            'handler' => 'views_handler_relationship',
            'label' => 'Base Node'
        )
    );
    $data['progression_counter']['counterType'] = array(
        'title' => t('Counter Type'),
        'help' => t('Discriminates between countups and countdowns.'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE
        ),
        'sort' => array(
            'handler' => 'views_handler_sort'
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string'
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string'
        )
    );
    $data['progression_counter']['targetDate'] = array(
        'title' => t('Target Date'),
        'help' => t('The target date for this counter.'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE
        ),
        'sort' => array(
            'handler' => 'views_handler_sort'
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string'
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string'
        )
    );

    return $data;
}
