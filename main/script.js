var brightness = document.getElementById("brightness");
var brightness_val = document.getElementById("brightness-val");

brightness_val.innerHTML = brightness.value;

brightness.oninput = function () {
    brightness_val.innerHTML = this.value;
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            //console.log(xhr.responseText);
        }
    };
    xhr.open("POST", "json_write.php", true);
    xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xhr.send("brightness=" + encodeURIComponent(this.value));
}

function updateContent(data) {
    var jsonDataContainer = document.getElementById('jsonDataContainer');
    jsonDataContainer.innerHTML = data;
}

function getJSONData() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState === 4 && xhr.status === 200) {
            var data = JSON.parse(xhr.responseText);
            updateContent(data.brightness);
        }
    };
    xhr.open('GET', 'json_read.php', true);
    xhr.send();
}

setInterval(getJSONData, 5000);
getJSONData();
