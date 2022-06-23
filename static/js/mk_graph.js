/**
 *  'rgba(255, 99, 132, 1)',    -  pinkish red
    'rgba(54, 162, 235, 1)',    - skye blue 
    'rgba(255, 206, 86, 1)',    - yellowish
    'rgba(75, 192, 192, 1)',    - cyan
    'rgba(153, 102, 255, 1)',   - violet
    'rgba(255, 159, 64, 1)'     - golden / orangish
 */

const ctx = document.getElementById('graph').getContext('2d');
const myChart = new Chart(ctx, {
	type: 'line',
	data: {
		labels: [''],
		datasets: [
			{
				label: 'Temperature (°C)',
				data: [],
				backgroundColor: ['rgba(255, 159, 64, 1)'],
				borderColor: ['rgba(255, 159, 64, 1)'],
				borderWidth: 2,
			},
			{
				label: 'Humidity (%)',
				data: [],
				backgroundColor: ['rgba(75, 192, 192, 1)'],
				borderColor: ['rgba(75, 192, 192, 1)'],
				borderWidth: 2,
			},
			{
				label: 'CO (%)',
				data: [],
				backgroundColor: ['rgba(255, 99, 132, 1)'],
				borderColor: ['rgba(255, 99, 132, 1)'],
				borderWidth: 2,
			},
		],
	},
	options: {
		scales: {
			y: {
				beginAtZero: true,
			},
		},
		plugins: {
			zoom: {
				zoom: {
					wheel: {
						enabled: true,
					},
					drag: {
						enabled: true,
					},
				},
			},
		},
	},
});

/* @params:
    AQ: Air Quality (ppm)
    T: Temperature (deg cel)
    H: Humidity %
    CO: Carbon monoxide %
*/
function updateGraph(T, H, CO) {
	if (myChart.data.datasets[0].data.length > 10) {
		myChart.data.datasets[0].data.splice(0, 1);
		myChart.data.datasets[1].data.splice(0, 1);
		myChart.data.datasets[2].data.splice(0, 1);
		myChart.data.labels.splice(0, 1);

		myChart.update();
	}

	if (
		myChart.data.datasets[0].data.at(-1) != T ||
		myChart.data.datasets[1].data.at(-1) != H ||
		myChart.data.datasets[2].data.at(-1) != CO ||
		myChart.data.datasets[0].data.length == 1
	) {
		myChart.data.datasets[0].data.push(T);
		myChart.data.datasets[1].data.push(H);
		myChart.data.datasets[2].data.push(CO);

		myChart.data.labels.push('');
		myChart.update();
	}
	// console.log(myChart.data.datasets);
}
