<?php

function social_wall_twitter_admin_settings() {

  $social_wall_twitter_settings_key = 'social_wall_twitter_settings';

  $social_wall_twitter_settings = variable_get($social_wall_twitter_settings_key);

  $form[$social_wall_twitter_settings_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#group' => 'additional_settings',
  );

  $form[$social_wall_twitter_settings_key]['consumer_key'] = array(
    '#type' => 'textfield',
    '#title'  => t('Consumer key'),
    '#default_value' => $social_wall_twitter_settings ? $social_wall_twitter_settings['consumer_key'] : null,
  );

  $form[$social_wall_twitter_settings_key]['consumer_secret'] = array(
    '#type' => 'textfield',
    '#title'  => t('Consumer secret'),
    '#default_value' => $social_wall_twitter_settings ? $social_wall_twitter_settings['consumer_secret'] : null,
  );

  return system_settings_form($form);
}

