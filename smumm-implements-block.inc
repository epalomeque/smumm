<?php

  drupal_add_css(
    drupal_get_path('module', 'smumm') . '/css/smumm-styles.css', 
    array(
      'group' => CSS_DEFAULT, 'every_page' => TRUE
    )
  );

  // Implementacion del bloque de menu en <front>
  // Implementa hook_block_info()
  function smumm_block_info() {
      $blocks['bloque_smumm_menufront'] = array(
      // Título del bloque en la configuración del administrador 
      'info' => t('Menu SMUMM'),
      'cache' => DRUPAL_NO_CACHE,
    );
    return $blocks;
  }

  // Implementa hook_block_view()
  function smumm_block_view($delta = '') {
    $block = array();
    $smumm_menu_printable = smumm_crea_menu();
    //dpm($smumm_menu_printable, 'smumm_menu_printable');
    switch ($delta) {
      case 'bloque_smumm_menufront':
        // Título del bloque.
        $block['subject'] = t('Menu SMUMM');
        // Función que retorna el contenido o función que se quiere en el bloque.
        //$block['content'] = drupal_render( $smumm_menu_printable );
        $block['content'] = theme('links', $smumm_menu_printable );
        break;
      }
      return $block;
  }

  // Implementa funcion hook_boton_editar()
  function smumm_crea_menu() {
  drupal_set_message();
  $mimenuelegido = variable_get('eligeMenu');

  if ( variable_get('eligeMenu') != null ) {
    // ****** Este es el bueno 
    //$smumm_menu_navigation = menu_tree( $mimenuelegido );


    $menu = menu_load_links($mimenuelegido);
    // $menu = menu_navigation_links($mimenuelegido);
    dpm($menu, 'menu');
    //return theme('links', $menu);

    // $smumm_menu_navigationL1 = 
    //   menu_navigation_links( $mimenuelegido, 0 );
    // $smumm_menu_navigationL11 = 
    //   menu_tree_page_data($mimenuelegido);
    
    // $smumm_menu_render = drupal_render($smumm_menu_navigation);
    // dpm ($smumm_menu_render, 'smumm_menu_render');
    // dpm($mimenuelegido, 'mimenuelegido');
    // dpm($smumm_menu_navigation, 'smumm_menu_navigation');
    // dpm($smumm_menu_navigationL1, 'smumm_menu_navigationL1');
    // dpm($smumm_menu_navigationL11, 'smumm_menu_navigationL11');
  } else { 
    $smumm_menu_navigation = 'Debes elegir un menu en la página de configuración';
  }

  return $menu;
  }

?>
