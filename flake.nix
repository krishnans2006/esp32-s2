{
  description = "A Nix flake for ESP IDF";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  inputs.esp-dev.url = "github:mirrexagon/nixpkgs-esp-dev";

  outputs = { self, nixpkgs, esp-dev }: {
    devShells."x86_64-linux".default = let
      pkgs = import nixpkgs { system = "x86_64-linux"; overlays = [ esp-dev.overlays.default ]; };
    in pkgs.mkShell {
      name = "default";

      buildInputs = with pkgs; [
        esp-idf-full
      ];
    };
  };
}
