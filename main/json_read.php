<?php 
    $control_json = file_get_contents('control.json');
    
    header('Content-Type: application/json');

    echo $control_json;
?>