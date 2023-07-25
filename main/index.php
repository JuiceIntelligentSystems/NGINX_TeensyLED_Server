<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED Control</title>
    <link rel="icon" href="data:,">
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
    <h1>
        LED CONTROL
    </h1>
    <p>
        <?php
        $control_json = file_get_contents('control.json');
        $json_decoded = json_decode($control_json);
        $output = $json_decoded->{'brightness'};
        echo "<input id='brightness' type='range' min='0' max='100' step='1' value='$output'>";
        ?>
        <span id="brightness-val"></span>
    </p>
    <span>OUTPUT JSON: <span id="jsonDataContainer"></span></span>
    <script src="script.js"></script>
</body>

</html>