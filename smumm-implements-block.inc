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
    dpm(variable_get('eligeMenu'),'$eligeMenu');
    dpm(variable_get('eligePagina'),'$eligePagina');

    $block = array();
    $smumm_menu_parender = smumm_crea_menu();
    switch ($delta) {
      case 'bloque_smumm_menufront':
        // Título del bloque.
        $block['subject'] = t('Menu SMUMM');
        // Función que retorna el contenido o función que se quiere en el bloque.
        $block['content'] = $smumm_menu_parender;
        break;
      }
      return $block;
  }

 
  function smumm_crea_menu() {
  drupal_set_message();
  $mimenuelegido = variable_get('eligeMenu');

  if ( variable_get('eligeMenu') != null ) {

    $mi_contador = 0;
    $menu3 = menu_tree($mimenuelegido);
    
    dpm($menu3, 'menu_tree');

    $mihtml = "<div class='container'>";

    $mihtml .= "<ul>";

    foreach ($menu3 as $item ) {

      $mi_contador++;
      if ($mi_contador == 1) { $mihtml .= "<div class='row'>"; }

      $misclases = "";
      
      if ( isset($item['#href']) && !empty($item['#href']) ) {
      
        $milink = ($item['#href'] == '<front>') ? "/" : $item['#href'] ;
        foreach ($item['#attributes']['class'] as $lasclases) {
          $misclases .= $lasclases . " ";
        }        

        $mihtml .= "<div class='col-md-4'>";
        $mihtml .= "<li class='". $misclases;
        $mihtml .= "'> <hr /> <a href='". $milink . "'> <strong>";
        $mihtml .= $item['#title']. "</strong><br />";
        $mihtml .= $item['#localized_options']['attributes']['title'];
        $mihtml .= "</a>";
        $mihtml .= "</li> </div>";

      }

      if ( ($mi_contador == 3) || ($item === end($menu3)) ) 
        { $mihtml .= "</div>"; $mi_contador = 0; }

    }

    $mihtml .= "</ul>";

  } else { 
    $smumm_menu_navigation = 'Debes elegir un menu en la página de configuración';
  }

  return $mihtml;
  }

?>
