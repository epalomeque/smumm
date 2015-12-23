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
    $smumm_menu_parender = smumm_crea_menu();
    switch ($delta) {
      case 'bloque_smumm_menufront':
        // Título del bloque.
        $block['subject'] = t('Menu SMUMM');
        // Función que retorna el contenido o función que se quiere en el bloque.
        $block['content'] = drupal_render($smumm_menu_parender);
        break;
      }
      return $block;
  }

  // Implementa funcion hook_boton_editar()
  function smumm_crea_menu() {
  drupal_set_message();
  $mimenuelegido = variable_get('eligeMenu');

  if ( variable_get('eligeMenu') != null ) {

    // $menu2 = menu_build_tree($mimenuelegido);
    // dpm($menu2, 'menu_build_tree_func');

    $menu3 = menu_tree($mimenuelegido);
    dpm($menu3, 'menu_tree_func');

    // $menu4 = menu_tree_all_data($mimenuelegido);
    // dpm($menu4, 'menu_tree_all_data_func');

  } else { 
    $smumm_menu_navigation = 'Debes elegir un menu en la página de configuración';
  }

  return $menu3;
  }

?>
