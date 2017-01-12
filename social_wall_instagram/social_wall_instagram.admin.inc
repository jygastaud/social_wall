<?php


function social_wall_instagram_admin_settings() {

  $social_wall_instagram_settings_key = 'social_wall_instagram_settings';

  $social_wall_instagram_settings = variable_get($social_wall_instagram_settings_key);

  $form['#attached']['js'][] = drupal_get_path('module', 'social_wall_instagram') . '/js/commands.js';

  $form[$social_wall_instagram_settings_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Instagram settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#group' => 'additional_settings',
  );

  $form[$social_wall_instagram_settings_key]['client_key'] = array(
    '#type' => 'textfield',
    '#required' => true,
    '#title'  => t('Client key'),
    '#default_value' => $social_wall_instagram_settings ? $social_wall_instagram_settings['client_key'] : null,
  );

  $form[$social_wall_instagram_settings_key]['client_secret'] = array(
    '#type' => 'textfield',
    '#required' => true,
    '#title'  => t('Client secret'),
    '#default_value' => $social_wall_instagram_settings ? $social_wall_instagram_settings['client_secret'] : null,
  );

  if (isset($social_wall_instagram_settings['client_key']) && isset($social_wall_instagram_settings['client_secret'])) {
    $form[$social_wall_instagram_settings_key]['auth'] = array(
      '#type' => 'button',
      '#value'  => t('Get an access token'),
      '#ajax' => array(
        'callback' => 'social_wall_instagram_auth_callback'
      )
    );
  }

  return system_settings_form($form);
}

function social_wall_instagram_auth_callback(&$form, &$form_state) {

  return array(
    '#type' => 'ajax',
    '#commands' => array(
      array(
        'command' => 'open_instagram_auth_window',
        'url' => url('admin/config/social_wall/instagram/connect')
      )
    )
  );
}

function social_wall_instagram_connect() {
  // create store from social_wall_instagram_auth variable
  $store = new \Webmozart\KeyValueStore\ArrayStore(variable_get('social_wall_instagram_auth', array()));
  $provider = social_wall_instagram_get_token_provider($store);

  if (!isset($_GET['code'])) {
    drupal_goto($provider->getAuthorizationUrl());
  }

  $provider->setCode(check_plain($_GET['code']));

  $token = $provider->getToken();

  // persist store into social_wall_instagram_auth variable
  variable_set('social_wall_instagram_auth', $provider->getStore()->toArray());

  return array(
    '#markup' => 'New token is : ' . $token . ', you can now close this window'
  );
}


