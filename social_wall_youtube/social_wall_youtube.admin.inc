<?php

function social_wall_youtube_admin_settings() {

  $social_wall_youtube_settings_key = 'social_wall_youtube_settings';

  $social_wall_youtube_settings = variable_get($social_wall_youtube_settings_key);

  $form[$social_wall_youtube_settings_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Youtube settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#group' => 'additional_settings',
  );

  $form[$social_wall_youtube_settings_key]['api_key'] = array(
    '#type' => 'textfield',
    '#title'  => t('Api key'),
    '#default_value' => $social_wall_youtube_settings ? $social_wall_youtube_settings['api_key'] : null,
  );

  return system_settings_form($form);
}
