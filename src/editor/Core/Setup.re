/*
 * Setup.re
 *
 * Runtime configuration of dependencies
 */

[@deriving (show, yojson({strict: false, exn: true}))]
type t = {
  [@key "neovim"]
  neovimPath: string,
  [@key "node"]
  nodePath: string,
  [@key "textmateService"]
  textmateServicePath: string,
  [@key "bundledExtensions"]
  bundledExtensionsPath: string,
  [@key "configuration"]
  configPath: string,
};

let ofString = str => Yojson.Safe.from_string(str) |> of_yojson_exn;

let ofFile = filePath => Yojson.Safe.from_file(filePath) |> of_yojson_exn;

let init = () =>
  Revery.Environment.getExecutingDirectory() ++ "setup.json" |> ofFile;
