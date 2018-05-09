function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@/TextBook.exe", "@StartMenuDir@/TextBook.lnk",
            "workingDirectory=@TargetDir@", "iconPath=@TargetDir@/textbook.ico",
            "iconId=1", "description=Запустить электронный учебник");
    }
}
