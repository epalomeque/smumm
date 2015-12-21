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
    switch ($delta) {
      case 'bloque_smumm_menufront':
        // Título del bloque.
        $block['subject'] = t('Menu SMUMM');
        // Función que retorna el contenido o función que se quiere en el bloque.
        $block['content'] = drupal_render( smumm_crea_menu() );
        break;
      }
      return $block;
  }

  // Implementa funcion hook_boton_editar()
  function smumm_crea_menu() {

  if ( variable_get('eligeMenu') != null ) {
    //$smumm_menu_render =  menu_navigation_links(variable_get('eligeMenu'), 0);
    // ****** Este es el bueno 
    $smumm_menu_navigation = menu_tree( variable_get('eligeMenu') );
    
    //$smumm_menu_navigation = menu_navigation_links(variable_get('eligeMenu'), 0);
    //dpm ($smumm_menu_navigation, 'smumm_menu_navigation');
    
    // $smumm_menu_render = drupal_render($smumm_menu_navigation);
    // dpm ($smumm_menu_render, 'smumm_menu_render');
  } else { 
    $smumm_menu_navigation = 'Debes elegir un menu en la página de configuración';
  }

  return $smumm_menu_render;
  }

?>
