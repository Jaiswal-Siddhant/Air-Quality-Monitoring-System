async function getdata(list = false) {
	const data = await fetch('http://127.0.0.1:5000/api/get');
	const data2 = await data.json();
	// console.log(data2);
	if (!list)
		return [
			parseInt(data2.AQ / 10),
			parseInt(data2.T),
			parseInt(data2.H),
			parseInt(data2.CO / 10),
		];
	return data2;
}

setInterval(async () => {
	// Handle Chart
	let data = await getdata();
	for (let i = 0; i < data.length; i++) {
		const options = {
			index: i + 1,
			percent: data[i],
			animationSmooth: '1.5s ease-out',
			colorSlice: getColor(data[i]),
			fontColor: getColor(data[i]),
			fontWeight: 600,
			animationSmooth: '3s ease-in',
		};
		circle.animationTo(options);
	}

	// Handle Graph
	updateGraph(data[1], data[2], 0);
}, 1500);
