<?php
$field1Value = $_POST['field1Value'];
$field2Value = $_POST['field2Value'];
$field3Value = $_POST['field3Value'];
$field4Value = $_POST['field4Value'];

$command = escapeshellcmd('prediction.py'); // Replace with the actual command to execute the Python script
$output = shell_exec($command . ' ' . $field1Value . ' ' . $field2Value . ' ' . $field3Value . ' ' . $field4Value);

echo trim($output);
?>
