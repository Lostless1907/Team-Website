let physicsStep;

Module.onRuntimeInitialized = () => {
    console.log("Inverse Matrix Engine: Connected.");
    
    // Wrap the C++ functions for easy JS use
    physicsStep = Module.cwrap('step_physics', 'number', ['number', 'number']);
    const initSim = Module.cwrap('init_sim', null, ['number']);

    initSim(0.0); // Start at 0 altitude
    runSimulation();
};

let altitude = 0;
function runSimulation() {
    // Step the C++ physics (0.016s is approx 60fps)
    // Passing 0 as the second argument (no thrust override)
    altitude = physicsStep(0.016, 0);

    // Update the website UI
    const display = document.getElementById('altitude-display');
    if (display) {
        display.innerText = `ALTITUDE: ${altitude.toFixed(2)}m`;
    }

    // Move a visual element if you have one
    const drone = document.getElementById('drone-visual');
    if (drone) {
        drone.style.bottom = `${altitude * 20}px`; 
    }

    requestAnimationFrame(runSimulation);
}
