<?php
// $Id$

/**
 * Menu callback; form builder function for Progression settings.
 *
 * @return array a form definition structure array
 */
function progression_admin_settings() {
    $form['progression_general_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('General Settings'),
        '#collapsible' => FALSE
    );

    $form['progression_general_settings']['progression_prune_countdowns'] = array(
        '#type' => 'checkbox',
        '#title' => t('Prune expired countdowns'),
        '#default_value' => variable_get('progression_prune_countdowns', 0),
        '#description' => t('The Progression module will prune countdowns (i.e. delete them from the database) once they expire.')
    );
    $form['progression_general_settings']['progression_prune_offset'] = array(
        '#type' => 'textfield',
        '#title' => t('Prune offset'),
        '#default_value' => variable_get('progression_prune_offset', 1),
        '#field_suffix' => t('days'),
        '#description' => t('The number of days to wait before a countdown is pruned.')
    );

    return system_settings_form($form);
}

/**
 * Form validation handler for the Progression admin settings form.
 *
 * @param array $form the   form definition structure array being validated
 * @param array $form_state the form state array
 */
function progression_admin_settings_validate($form, &$form_state) {
    $pruneOffset = $form_state['values']['progression_prune_offset'];

    if (!is_int($pruneOffset)) {
        form_set_error('progression_prune_offset', t('The prune offset must be a valid integer.'));
    }
    else if ($pruneOffset <= 0) {
        form_set_error('progression_prune_offset', t('The prune offset must be a positive integer.'));
    }
}
