char main_html[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\r\n"
"<html xmlns=\"http://www.w3.org/1999/xhtml\" >\r\n"
"<head>\r\n"
"    <title>AMMYY Router - Statistics</title>\r\n"
"</head>\r\n"
"<script>\r\n"
"window.setInterval(\"getStat1()\", 1000);\r\n"
"</script>\r\n"
"<body>\r\n"
"\r\n"
"	<table>\r\n"
"	<tr>\r\n"
"	<td width=\"300px\">\r\n"
"\r\n"
"    <table id=\"tblStatistics\" border=\"1px\">\r\n"
"    <tr><td>Total connections:</td><td align='right' width=\"100px\">-</td></tr>\r\n"
"    <tr><td>- target:</td>  <td align='right'>-</td></tr>\r\n"
"	<tr><td>- viewer:</td>  <td align='right'>-</td></tr>\r\n"
"	<tr><td>- control:</td> <td align='right'>-</td></tr>\r\n"
"	<tr><td>- unknown:</td> <td align='right'>-</td></tr>\r\n"
"	<tr><td>Sessions:</td>  <td align='right'>-</td></tr>\r\n"
"	<tr><td>Max recv:</td>  <td align='right'>-</td></tr>\r\n"
"	<tr><td>Max sent:</td>  <td align='right'>-</td></tr>\r\n"
"	<tr><td>Bytes recv:</td><td align='right' nowrap>-</td></tr>\r\n"
"	<tr><td>Bytes sent:</td><td align='right' nowrap>-</td></tr>\r\n"
"	<tr><td>Speed recv:</td><td align='right'>-</td></tr>\r\n"
"	<tr><td>Speed sent:</td><td align='right'>-</td></tr>\r\n"
"    </table>\r\n"
"\r\n"
"	</td>\r\n"
"	<td valign=\"top\">\r\n"
"\r\n"
"	<table id=\"tbl3\" border=\"1px\">\r\n"
"	<tr><td>Stat with control<br>connections</td><td>%s</td><td><input type=\"button\" value=\"Change\" onclick=\"getStat3(0);\"/></td></tr>\r\n"
"	<tr><td>TCP Nagle</td>                   <td>%s</td><td><input type=\"button\" value=\"Change\" onclick=\"getStat3(1);\"/></td></tr>\r\n"
"	<tr><td>Debug log</td>                   <td>%s</td><td><input type=\"button\" value=\"Change\" onclick=\"getStat3(2);\"/></td></tr>\r\n"
"	<tr><td>Listen ports</td><td>%s</td><td>&nbsp;</td></tr>\r\n"
"	<tr><td>Listen ip</td><td>%s</td><td>&nbsp;</td></tr>\r\n"
"	<tr><td>Build time</td><td>%s</td><td>&nbsp;</td></tr>\r\n"
"	<tr><td>Started time (UTC)</td><td>%s</td><td>&nbsp;</td></tr>\r\n"
"	<tr><td>Current time (UTC)</td><td>%s</td><td>&nbsp;</td></tr>\r\n"
"	</table>\r\n"
"\r\n"
"	</td>\r\n"
"	</tr>\r\n"
"	</table>\r\n"
"\r\n"
"\r\n"
"    <br>\r\n"
"\r\n"
"    <select id=\"ctlClient\" style=\"width:400px\">\r\n"
"		<option value=\"0\">&lt;ALL&gt;</option>\r\n"
"    </select>\r\n"
"    <input type=\"button\" value=\"Refresh\" onclick=\"getStat2();\"/>\r\n"
"\r\n"
"    <br>\r\n"
"    <br>\r\n"
"    <table id=\"tblPerClient\" border=\"1px\">\r\n"
"		<tr><th width=\"200px\">&nbsp;</th><th width=\"100px\">total</th><th width=\"100px\">target</th><th width=\"100px\">viewer</th></tr>\r\n"
"		<tr><td>Bytes recv</td>	 <td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"		<tr><td>Recv Packets</td><td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"		<tr><td>Send Packets</td><td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"		<tr><td>Max Recv Packet Size</td><td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"		<tr><td>Max Send Packet Size</td><td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"		<tr><td>Max Queue Size</td>      <td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"		<tr><td>Queue Size</td>          <td align='right'></td><td align='right'></td><td align='right'></td></tr>\r\n"
"    </table>\r\n"
"\r\n"
"\r\n"
"<script language=\"javascript\" type=\"text/javascript\">\r\n"
"\r\n"
"function GetXmlHttpObject()\r\n"
"{\r\n"
"	var xmlHttp=null;\r\n"
"	try\r\n"
"	{\r\n"
"		// Firefox, Opera 8.0+, Safari\r\n"
"		xmlHttp=new XMLHttpRequest();\r\n"
"	}\r\n"
"	catch (e)\r\n"
"	{\r\n"
"		// Internet Explorer\r\n"
"	try\r\n"
"	{\r\n"
"		xmlHttp=new ActiveXObject(\"Msxml2.XMLHTTP\");\r\n"
"	}\r\n"
"	catch (e)\r\n"
"	{\r\n"
"		xmlHttp=new ActiveXObject(\"Microsoft.XMLHTTP\");\r\n"
"	}\r\n"
"	}\r\n"
"	return xmlHttp;\r\n"
"}\r\n"
"\r\n"
"function AddDigitGrouping(s1)\r\n"
"{\r\n"
"	var s2 = \"\";\r\n"
"	\r\n"
"	if (s1.constructor==String) {\r\n"
"		var len = s1.length;\r\n"
"		var i = 0;\r\n"
"		var n = 0;\r\n"
"		while(i<len) {\r\n"
"			if (i>0) {\r\n"
"				s2+=\" \";\r\n"
"				n=3;\r\n"
"			}\r\n"
"			else {\r\n"
"				n=(len%%3);\r\n"
"				if (n==0) n=3;\r\n"
"			}\r\n"
"			\r\n"
"			s2+=s1.substr(i,n);\r\n"
"			i+=n;\r\n"
"		}\r\n"
"	}\r\n"
"	return s2;\r\n"
"}\r\n"
"\r\n"
"\r\n"
"function getStat2()\r\n"
"{\r\n"
"	var objClient = document.getElementById(\"ctlClient\");\r\n"
"\r\n"
"	while (objClient.options.length > 1) objClient.remove(1);\r\n"
"        \r\n"
"	var xmlHttp=GetXmlHttpObject();\r\n"
"	xmlHttp.onreadystatechange=function()\r\n"
"    {\r\n"
"		if(xmlHttp.readyState==4)\r\n"
"		{\r\n"
"			var s = xmlHttp.responseText;\r\n"
"			var arrVals = s.split(\";\");\r\n"
"			var n = arrVals.length;\r\n"
"			for(var k=0; k<n;) {\r\n"
"				var oElem = document.createElement (\"OPTION\");\r\n"
"                oElem.text  = arrVals[k++];\r\n"
"                oElem.value = arrVals[k++];\r\n"
"                objClient.options.add(oElem);\r\n"
"			}\r\n"
"		}\r\n"
"	}\r\n"
"	xmlHttp.open(\"GET\",\"/stat2.html{PASSWORD}\",true);\r\n"
"    xmlHttp.send(null);\r\n"
"}\r\n"
"\r\n"
"function getStat1()\r\n"
"{       \r\n"
"	var objClient = document.getElementById(\"ctlClient\");\r\n"
"	var objStatistics = document.getElementById(\"tblStatistics\");\r\n"
"\r\n"
"	var xmlHttp=GetXmlHttpObject();\r\n"
"	xmlHttp.onreadystatechange=function()\r\n"
"	{\r\n"
"		if(xmlHttp.readyState==4)\r\n"
"        {\r\n"
"			var s = xmlHttp.responseText;\r\n"
"            var arrVals = s.split(\";\");\r\n"
"\r\n"
"			var k=0;\r\n"
"\r\n"
"			if (arrVals[k++]==\"1\") { // need to delete from combo-box\r\n"
"				if (objClient.selectedIndex > 0) {\r\n"
"					objClient.remove(objClient.selectedIndex);\r\n"
"					objClient.selectedIndex = 0;\r\n"
"				}\r\n"
"			}\r\n"
"\r\n"
"            for(var i=0;i<12;i++) {\r\n"
"				objStatistics.rows[i].cells[1].innerHTML = AddDigitGrouping(arrVals[k++]);\r\n"
"            }			\r\n"
"                \r\n"
"			for(var col=1;col<4;col++) {				\r\n"
"            for(var row=1;row<8;row++) {\r\n"
"				var val = arrVals[k++];\r\n"
"					val = (val==\"\") ? \"&nbsp;\" : AddDigitGrouping(val);\r\n"
"				document.getElementById(\"tblPerClient\").rows[row].cells[col].innerHTML = val;\r\n"
"            }\r\n"
"			}\r\n"
"		}\r\n"
"	}		\r\n"
"	var sUrl = \"/stat1.html{PASSWORD}&id=\" + objClient.options[objClient.selectedIndex].value;\r\n"
"    xmlHttp.open(\"GET\",sUrl,true);\r\n"
"    xmlHttp.send(null);\r\n"
"}\r\n"
"\r\n"
"function getStat3(nRow)\r\n"
"{  		\r\n"
"	var xmlHttp=GetXmlHttpObject();\r\n"
"        xmlHttp.onreadystatechange=function()\r\n"
"    {\r\n"
"		if(xmlHttp.readyState==4)\r\n"
"        {\r\n"
"			var obj3 = document.getElementById(\"tbl3\");\r\n"
"            var s = xmlHttp.responseText;\r\n"
"                \r\n"
"			obj3.rows[nRow].cells[1].innerHTML = s;\r\n"
"		}\r\n"
"	}\r\n"
"	var sUrl = \"/stat3.html{PASSWORD}&row=\" + nRow;\r\n"
"    xmlHttp.open(\"GET\",sUrl,true);\r\n"
"    xmlHttp.send(null);\r\n"
"}\r\n"
"\r\n"
"</script>\r\n"
"\r\n"
"</body>\r\n"
"</html>\r\n";
