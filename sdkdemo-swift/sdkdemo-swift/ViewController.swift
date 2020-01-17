//
//  ViewController.swift
//  sdkdemo-swift
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

import UIKit

import RBSDKPlayer

class ViewController: UIViewController {

    @IBOutlet weak var playerContainerView: UIView!
    var playerController: RBSDKPlayerViewController?

    override func viewDidLoad() {
        super.viewDidLoad()

        RBSDK.sharedInstance().loadAsynchronously { success, error in
            if (success) {
                DispatchQueue.main.async {
                    // Load Player with a Reel Id
                    self.loadPlayerWithReelId()

                    // Load Player with a Collection Id
//                    self.loadPlayerWithCollectionId()
                }
            } else if let error = error {
                print("Error trying to configure the sdk: \(error.localizedDescription)")
            }
        }
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()

        if let bounds = playerContainerView?.bounds {
            playerController?.view.frame = bounds
        }
    }

    // MARK: - Private methods

    private func loadPlayerWithReelId() {
        let options: RBSDKPlayerOption = [.autoPlay]
        let reelId = "#SET A REEL ID PROVIDED BY THE RHINOBIRD DASHBOARD#"
        playerController = RBSDKRhinobirdPlayerViewController(reelId: reelId,
                                                              options: options,
                                                              delegate: self)
        attachPlayerController()
    }

    private func loadPlayerWithCollectionId() {
        let options: RBSDKPlayerOption = [.autoPlay]
        let collectionId = "#SET A COLLECTION ID PROVIDED BY THE RHINOBIRD DASHBOARD#"
        playerController = RBSDKRhinobirdPlayerViewController(collectionId: collectionId,
                                                              options: options,
                                                              delegate: self)
        attachPlayerController()
    }

    private func attachPlayerController() {
        guard let playerController = playerController else { return }

        addChild(playerController)
        playerController.view.frame = playerContainerView.bounds
        playerContainerView.addSubview(playerController.view)
    }
}

// MARK: RBPlayerViewControllerDelegate

extension ViewController: RBSDKPlayerViewControllerDelegate {

    func playerControllerLoadDidSucceed(_ succeed: Bool, withError error: Error?) {
        if (succeed) {
            print("Player load succeed")
        } else if let errorDescription = error?.localizedDescription {
            print("Player was not able to load, error: \(errorDescription)")
        } else {
            print("Player was not able to load")
        }
    }
}

