<?php

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
        $block['content'] = smumm_crea_menu();
        break;
      }
      return $block;
  }

  // Implementa funcion hook_boton_editar()
  function smumm_crea_menu() {

  if ( variable_get('eligeMenu') != null ) {
    $smumm_menu_block = menu_load(variable_get('eligeMenu'));
    print_r($smumm_menu_block);
  } else { 
    $smumm_menu_block = 'eligeMenu es null';
  }

    return $smumm_menu_block;
  }

?>
