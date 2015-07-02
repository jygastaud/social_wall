<?php

function social_wall_facebook_admin_settings() {

  $social_wall_facebook_settings_key = 'social_wall_facebook_settings';

  $social_wall_facebook_settings = variable_get($social_wall_facebook_settings_key);

  $form[$social_wall_facebook_settings_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#group' => 'additional_settings',
  );

  $form[$social_wall_facebook_settings_key]['client_key'] = array(
    '#type' => 'textfield',
    '#title'  => t('Client key'),
    '#default_value' => $social_wall_facebook_settings ? $social_wall_facebook_settings['client_key'] : null,
  );

  $form[$social_wall_facebook_settings_key]['client_secret'] = array(
    '#type' => 'textfield',
    '#title'  => t('Client secret'),
    '#default_value' => $social_wall_facebook_settings ? $social_wall_facebook_settings['client_secret'] : null,
  );

  return system_settings_form($form);
}
