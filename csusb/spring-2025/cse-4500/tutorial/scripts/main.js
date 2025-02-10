const myImage = document.querySelector("img");

myImage.onclick = () => {
    const mySrc = myImage.getAttribute("src");
    if(mySrc == "images/davegar.png")
    {
        myImage.setAttribute("src", "images/trident.png");
    } else {
        myImage.setAttribute("src", "images/davegar.png")
    }
}
