var InitDemo = function () {
  console.log("working")

  var canvas = document.getElementById('game-surface')
  var gl = canvas.getContext('webgl')

  if (!gl) {
    console.log('using experimental-webgl')
    gl = canvas.getContext('experimental-webgl')
  }
  if (!gl) {
    alert('Browser does not support WebGL')
  }

  // canvas.width = window.innerWidth;
  // canvas.height = window.innerHeight;
  // gl.viewport(0, 0, window.innerWidth, window.innerHeight)

  gl.clearColor(0.2, 0, 0, 1)
  gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT)
};