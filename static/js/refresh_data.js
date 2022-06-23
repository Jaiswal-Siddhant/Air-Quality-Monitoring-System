const AQ = document.getElementById('AQ');
const CO = document.getElementById('CO');
const Hydrogen = document.getElementById('Hydrogen');
const Temp = document.getElementById('Temp');
const Humid = document.getElementById('Humid');
const Other = document.getElementById('Other');

setInterval(async () => {
	let data = await getdata(true);
	AQ.innerText = parseInt(data.AQ);
	CO.innerText = parseInt(data.CO);
	Hydrogen.innerText = parseInt(data.H2);
	Temp.innerText = `${parseInt(data.T)}°C`;
	Humid.innerText = `${parseInt(data.H)}%`;
	Other.innerText = parseInt(data.AQ - 193);
}, 1500);
