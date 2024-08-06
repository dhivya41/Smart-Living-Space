<?php
    $eeg=$_GET['eeg'];
    $db=mysqli_connect("localhost","id21105897_project1","Iamproject@1","id21105897_project") or die(mysqli_connect_error());
mysqli_query($db,"UPDATE `home` SET `eeg`='$eeg'")or die(mysqli_error($db));

?>