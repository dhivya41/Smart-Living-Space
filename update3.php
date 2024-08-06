 <?php
  $db=mysqli_connect("localhost","id21105897_project1","Iamproject@1","id21105897_project") or die(mysqli_connect_error());
$query=mysqli_query($db,"SELECT * FROM `door` ") or die(mysqli_error($db));

while($row=mysqli_fetch_array($query))
{   
 $status=$row['status'];
 }
 echo "*a".$status."b";

?>