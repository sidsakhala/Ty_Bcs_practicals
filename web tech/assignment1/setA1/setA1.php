<?php
	
	
	if(isset($_COOKIE['accesses'])){
		$_COOKIE['accesses'] = $_COOKIE['accesses'] +1;		
		//$page_accesses = $_COOKIE['accesses'];
		
		//setcookie('accesses',++$page_accesses);

	}else{
		setcookie('accesses',1);	
		}

		echo "This page is accessed ".$_COOKIE['accesses']." times";



?>
