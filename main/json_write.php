<?php
if (isset($_POST["brightness"])) {
    $brightness = $_POST["brightness"];

    $ledJson = new stdClass();
    $ledJson->brightness = $brightness;

    $ledJson = json_encode($ledJson);

    $handle = fopen("control.json", 'a');
    if (flock($handle, LOCK_EX)) {
        file_put_contents("control.json", $ledJson);
        flock($handle, LOCK_UN);
        fclose($handle);
    } else {
        fclose($handle);
        die("Failed To Acquire The Lock on The File.");
    }
}
