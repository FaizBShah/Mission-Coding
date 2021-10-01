btn=document.getElementById("changeColor");
infoText=document.getElementById("colorInfo");
container=document.getElementById("container");

let hexValue;

btn.addEventListener("click", btnClick);


function btnClick(){

    let random= Math.floor(100000+(899999*Math.random()));
    hexValue=random;
    container.style=`background-color:#${hexValue}`;
    console.log("btnclicked!");

    infoText.innerHTML=`<p> Background Color = #${hexValue}</p>`;

}

