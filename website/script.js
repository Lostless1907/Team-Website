// --- Inverse Matrix Bridge Logic ---

let physicsStep;
let altitude = 0;
let isEngineLoaded = false;

// 1. Initialize the Wasm Module
Module.onRuntimeInitialized = () => {
    console.log("INVERSE_MATRIX_ENGINE: ONLINE");
    
    // Bridge the C++ functions to JS
    // cwrap(name, return_type, [arg_types])
    physicsStep = Module.cwrap('step_physics', 'number', ['number', 'number']);
    const initSim = Module.cwrap('init_sim', null, ['number']);

    // Initialize with 0.0 altitude
    initSim(0.0);
    isEngineLoaded = true;
    
    // Start the real-time loop
    updateLoop();
};

// 2. The High-Speed Physics Loop
function updateLoop() {
    if (!isEngineLoaded) return;

    // Time delta (0.016s = 60fps)
    const dt = 0.016; 
    const manualThrust = 0; // Can be linked to a slider/button later

    // CALL THE C++ ENGINE
    altitude = physicsStep(dt, manualThrust);

    // Update the UI
    renderUI();

    // Loop at 60fps
    requestAnimationFrame(updateLoop);
}

// 3. Render the output to the page
function renderUI() {
    // Update text display
    const altDisplay = document.getElementById('altitude-display');
    if (altDisplay) {
        altDisplay.innerText = `ALTITUDE: ${altitude.toFixed(3)}m`;
    }

    // Update visual drone position
    const drone = document.getElementById('drone-visual');
    if (drone) {
        // Simple scaling: 1m = 20px
        drone.style.bottom = `${altitude * 20}px`; 
    }
}
