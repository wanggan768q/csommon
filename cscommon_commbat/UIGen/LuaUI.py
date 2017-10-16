#!/usr/bin/python
#import xmltodict
import sys
import os
#Function:Analyze json script
#Json is a script can descript data structure as xml, 
#for detail, please refer to "http://json.org/json-zh.html".

#Note:
#Also, if you write json script from python,
#you should use dump instead of load. pleaser refer to "help(json)".

layerName = ""
templateContent0 = 'local $name$ = class("$name$", '
templateContent = ''
templateContent1 = ''')
function $name$:ctor( controller,model )

	$name$.super.ctor(self,controller,model )
    self:addCCSChild("CCSUI/$name$.csb")

$items$

    self:setContent()
	--sendSyncData
end

$itemcbs$

function $name$:modelDataUpdate( obj )
    
end

function $name$:onExitTransitionDidStart( ... )
    $name$.super.onExitTransitionDidStart(self)
end

function $name$:onEnter( ... )
    $name$.super.onEnter(self)
end

function $name$:onExit( ... )
    $name$.super.onExit(self)
end

function $name$:onEnterTransitionDidFinish( ... )
    $name$.super.onEnterTransitionDidFinish(self)
end

function $name$:onCleanup( ... )
    $name$.super.onCleanup(self)
end

function $name$:setContent( ... )

end

return $name$
'''

def xmlEle( itemName, itemType, touchEnable ,isChildRoot ):
    c1 = ""
    c2 = ""
    rootString = "self.root"
    tabString = "\t"
    if isChildRoot:
        rootString = "child_root"
        tabString = "\t\t\t"
    if( touchEnable != None and touchEnable=='True' ):
        if itemType == "TextObjectData" or itemType == "ImageViewObjectData" or itemType == "TextBMFontObjectData" or itemType == "TextAtlasObjectData" or itemType == "LoadingBarObjectData" :
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            c1 += tempItems
        if itemType == "ButtonObjectData" :
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            tempItems += "%sself.%s:addClickEventListener(handler(self,self.on%sClick))\r\n\r\n"%(tabString,itemName,itemName)
            tempCBs = "function %s:on%sClick( sender )\r\n\tif %s.super.updateGuideStep(self,sender) then\r\n\t\treturn\r\n\tend\r\nend\r\n\r\n"%(layerName,itemName,layerName)
            c1 += tempItems
            c2 += tempCBs
        elif itemType == "CheckBoxObjectData" :
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            tempItems += "%sself.%s:addEventListener(handler(self,self.on%sStateChanged))\r\n\r\n"%(tabString,itemName,itemName)
            tempCBs = '''function %s:on%sStateChanged( sender,eventType )
    if %s.super.updateGuideStep(self,sender) then
        return
    end
    if eventType == ccui.CheckBoxEventType.selected then
        
    elseif eventType == ccui.CheckBoxEventType.unselected then
        
    end
    
end\r\n\r\n'''%(layerName,itemName,layerName)
            c1 += tempItems
            c2 += tempCBs
        elif itemType == "TextFieldObjectData" :
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            tempItems += "%sself.%s:addEventListener(handler(self,self.on%sStateChanged))\r\n\r\n"%(tabString,itemName,itemName)
            tempCBs = '''function %s:on%sStateChanged( sender,eventType )
    if %s.super.updateGuideStep(self,sender) then
        return
    end
    if eventType == ccui.TextFiledEventType.attach_with_ime then

    elseif eventType == ccui.TextFiledEventType.detach_with_ime then

    elseif eventType == ccui.TextFiledEventType.insert_text then

    elseif eventType == ccui.TextFiledEventType.delete_backward then

    end    

end\r\n\r\n'''%(layerName,itemName,layerName)
            c1 += tempItems
            c2 += tempCBs
        elif itemType == "SliderObjectData":
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            tempItems += "%sself.%s:addEventListener(handler(self,self.on%sStateChanged))\r\n\r\n"%(tabString,itemName,itemName)
            tempCBs = '''function %s:on%sStateChanged( sender,eventType )
    if %s.super.updateGuideStep(self,sender) then
        return
    tend
    if eventType == ccui.SliderEventType.percentChanged then

    end
    
end\r\n\r\n'''%(layerName,itemName,layerName)
            c1 += tempItems
            c2 += tempCBs
        elif itemType == "PageViewObjectData" or itemType == "ScrollViewObjectData":
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            tempItems += "%sself.%s:addClickEventListener(handler(self,self.on%sClick))\r\n"%(tabString,itemName,itemName)
            tempCBs = "function %s:on%sClick( sender )\r\n\tif %s.super.updateGuideStep(self,sender) then\r\n\t\treturn\r\n\tend\r\nend\r\n\r\n"%(layerName,itemName,layerName)
            tempItems += "%sself.%s:addEventListener(handler(self,self.on%sEvent))\r\n\r\n"%(tabString,itemName,itemName)
            tempCBs += "function %s:on%sEvent( sender,eventType )\r\n\tif %s.super.updateGuideStep(self,sender) then\r\n\t\treturn\r\n\tend\r\nend\r\n\r\n"%(layerName,itemName,layerName)
            c1 += tempItems
            c2 += tempCBs
        elif itemType == "ListViewObjectData":
            tempItems = "%sself.%s = ccui.Helper:seekWidgetByName(%s, \"%s\")\r\n"%(tabString,itemName,rootString,itemName)
            tempItems += "%sself.%s:addClickEventListener(handler(self,self.on%sClick))\r\n"%(tabString,itemName,itemName)
            tempCBs = "function %s:on%sClick( sender )\r\n\tif %s.super.updateGuideStep(self,sender) then\r\n\t\treturn\r\n\tend\r\nend\r\n\r\n"%(layerName,itemName,layerName)
            tempItems += "%sself.%s:addTouchEventListener(handler(self,self.on%sTouch))\r\n\r\n"%(tabString,itemName,itemName)
            tempCBs += "function %s:on%sTouch( sender,eventType )\r\n\tif %s.super.updateGuideStep(self,sender) then\r\n\t\treturn\r\n\tend\r\nend\r\n\r\n"%(layerName,itemName,layerName)
            c1 += tempItems
            c2 += tempCBs
    return (c1,c2)

def getAttr( attrs, attrName ):
    for a in attrs:
        if cmp( a[0:len(attrName)], attrName ) == 0:
            return a.split('"')[1]
    return None

def toParseSubCsd( eleName, fileName ):
    global pathDir
    e1 = '''
	local %s=self.root:getChildByName("%s")
	if %s then
		local child_root=%s:getChildByName("root")
		if child_root  then\r\n'''%(eleName,eleName,eleName,eleName)
    e2 = '''        end 
	else 
		print(" child FileNode_TopInfo is nil ")
	end '''

    fName = pathDir + os.path.split(fileName)[1]
    if (fName.split(".")[-1]).lower() != "csd":
        return ("","")
        
   
    (dd1,dd2) = toParseCsdXML( fName,True )
    
    
    d1 = ( e1 + dd1 + e2)
    d2 = dd2
    #print dd1,dd2
    return (d1,d2)
    
AttributesNameSet = []

def toParseCsdXML( xmlFname, isChildRoot=False ):
    a1 = ""
    a2 = ""
    
    xmlContent = file(xmlFname)
    while 1:
        li = xmlContent.readline()
        if not li:
            break
        line = li.strip(" \r\n")
        if cmp(line[0:18],"<AbstractNodeData " ) == 0:
            attrs = line.split(' ')
            itemName = getAttr(attrs,"Name")
            if itemName in AttributesNameSet:
                continue
            AttributesNameSet.append(itemName)
            itemType = getAttr(attrs,"ctype")
            touchEnable = getAttr(attrs,"TouchEnable")
            if itemType != "ProjectNodeObjectData" :
                (aa1,aa2) = xmlEle( itemName, itemType, touchEnable, isChildRoot)
                a1 += aa1
                a2 += aa2
            else:
                while 1:
                    li = xmlContent.readline()
                    if not li:
                        break
                    line = li.strip(" \r\n")
                    if cmp(line[0:10],"<FileData " ) == 0:
                        attrs = line.split(' ')
                        Path = getAttr(attrs,"Path")
                        if Path != None:
                            (aa1,aa2) = toParseSubCsd( itemName, Path )
                            a1 += aa1
                            a2 += aa2
                        break
                    if cmp(line[0:19],"</AbstractNodeData>" ) == 0:
                        break
    xmlContent.close
    return (a1,a2)
    

if len(sys.argv) < 2 :
    print  "Syntax error, EG. %s UI.json"%(sys.argv[0]) 
    exit()


xmlFname = sys.argv[1]
pathNames = os.path.split(xmlFname)
pathDir = pathNames[0]
if len(pathDir)>0:
    pathDir = pathDir+"/"
csdName = pathNames[1]

layerName = csdName.split(".")[0]


if layerName.lower().rfind("node")>0:
	templateContent = templateContent0+"BaseNode"+templateContent1
else:
	templateContent = templateContent0+"BaseLayer"+templateContent1


(outputItems,outputItemCBs) = toParseCsdXML( xmlFname )


templateContent = templateContent.replace("$name$",layerName)
templateContent = templateContent.replace("$items$",outputItems)
templateContent = templateContent.replace("$itemcbs$",outputItemCBs)

outputFname = pathDir+"LUA/"+layerName + ".lua"
print outputFname
outputFile = file(outputFname,"wb")
outputFile.write(templateContent)
outputFile.close

print "OK"
